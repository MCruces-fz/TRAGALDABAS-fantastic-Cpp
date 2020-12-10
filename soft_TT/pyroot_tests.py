import ROOT
from os.path import join as join_path
from ROOT import gSystem
from ctypes import c_int, c_float

gSystem.Load("libtunpacker.so")

from ROOT import Unpacker, HldEvent, HldSubEvent, \
    RpcLookupTable, TActiveCells, TRpcCalPar, Hit, \
    EventHdr, Event, TRpcRaw, TRpcHit, TRpcRawF, \
    TRpcHitF, TRpcSaetaF, TTMatrix


def print_ttree(ttree):
    # Get only the seven branches:
    list_branches = ttree.GetListOfBranches()  # All branches in object list_branches
    num_branches = list_branches.GetEntries()  # 7 branches
    print(f"TTree named \"T\" ({num_branches} branches):")
    for br in range(num_branches):
        branch = list_branches.At(br)
        branch_name = branch.GetName()
        list_leaves = branch.GetListOfBranches()
        num_leavees = list_leaves.GetEntries()
        print(f"\t- {branch_name} ({num_leavees} leaves)")
        for lf in range(num_leavees):
            leaf = list_leaves.At(lf)
            full_leaf_name = leaf.GetName()
            br_nam, lf_nam = full_leaf_name.split('.')
            print(f"\t\t+ {lf_nam}")
            for value in range(45, 50, 1):
                print(f"\t\t\t* First Value {ttree.GetLeaf(f'{br_nam}.{lf_nam}').GetValue(value)}")
    #     if branch_name == "rpchit":
    #         break
    # return branch


DST_DIR = "/home/mcruces/Documents/PyROOT_Useful/pyroot_tutorial/DST/"
input_file_path = join_path(DST_DIR, "tr17289091625.hld.root.root")

# Open trFILE.hld.root.root as TFile
f = ROOT.TFile(input_file_path, "READ")

# Get the TTree named "T"
tree = f.Get("T")
rpchit_branch = tree.GetBranch("rpchit")
rpchit_leaves = rpchit_branch.GetListOfBranches()
rpchit_trbnum = rpchit_leaves.At(2)
trbnum_val = rpchit_trbnum.GetValue(0, 0)
print(f"trbnum value: {trbnum_val}")

# Print Tree
print_ttree(tree)

trbnum, cell, col, row = [c_int(0)] * 4
x, y, z, time, charge = [c_float(0)] * 5

hit = TRpcHit()
hit.getHit(trbnum, cell, col, row, x, y, z, time, charge)

print(trbnum, cell, col, row, x, y, z, time, charge)

use_all_imports = False
if __name__ == "__main__" and use_all_imports:
    print(help(Unpacker))
    help(HldEvent)
    help(HldSubEvent)
    help(RpcLookupTable)
    help(TActiveCells)
    help(TRpcCalPar)
    help(Hit)
    help(EventHdr)
    help(Event)
    help(TRpcRaw)
    help(TRpcHit)
    help(TRpcRawF)
    help(TRpcHitF)
    help(TRpcSaetaF)
    help(TTMatrix)
