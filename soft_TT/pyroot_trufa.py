import ROOT
from os.path import join as join_path

# TODO: Leer en un TClonesArray directamente del objeto TTree -> rpchit --> TClonesArray con fX, fY, fZ

DST_DIR = "/home/mcruces/Documents/PyROOT_Useful/pyroot_tutorial/DST/"
input_file_path = join_path(DST_DIR, "tr17289091625.hld.root.root")

# Open trFILE.hld.root.root as TFile
f = ROOT.TFile(input_file_path, "READ")

# Get the TTree named "T"
tree = f.Get("T")

nentries = tree.GetEntries()

print("Branches Names:")
for br in tree.GetListOfBranches():
    print(f"  - {br.GetName()}")

for entry in range(nentries)[:10]:
    ev = tree.GetEntry(entry)  # Para cada evento del tree hay que cargar todas las branches sino no existe el rpchit
    nhit = tree.rpchit.GetEntries()
    # print(f"Ttree entry: {tree.GetEntry(entry)}")
    # print(f"Ttree rpchit: {tree.rpchit}")
    print(f'@@@ ===== Event: {tree.GetEntry(entry)} ===== @@@')
    for ihit in range(nhit):
        print(f'----------- Hit: {ihit} -----------')
        print(f'fTrbnum: {tree.GetLeaf("rpchit.fTrbnum").GetValue(ihit):.0f}')
        print(f'fCell: {tree.GetLeaf("rpchit.fCell").GetValue(ihit):.0f}')
        print(f'fCol: {tree.GetLeaf("rpchit.fCol").GetValue(ihit):.0f}')
        print(f'fRow: {tree.GetLeaf("rpchit.fRow").GetValue(ihit):.0f}')
        print(f'fX: {tree.GetLeaf("rpchit.fX").GetValue(ihit):.3f}')
        print(f'fY: {tree.GetLeaf("rpchit.fY").GetValue(ihit):.3f}')
        print(f'fZ: {tree.GetLeaf("rpchit.fZ").GetValue(ihit):.3f}')
        print(f'fTime: {tree.GetLeaf("rpchit.fTime").GetValue(ihit):.3f}')
        print(f'fCharge: {tree.GetLeaf("rpchit.fCharge").GetValue(ihit):.3f}')
