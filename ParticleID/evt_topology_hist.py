import json
import matplotlib.pyplot as plt
from sys import argv
import csv
import numpy as np
from os.path import join as join_path

INP_DIR = "/home/mcruces/Documents/fptrucha_hits/outroot/"
OUT_DIR = "/home/mcruces/Documents/fptrucha_hits/outroot/"

file_path = argv[1]  # Full path to the CSV file

def crappyhist(d: dict, logscale: bool = False, width: int = 140, char: str = "#") -> str:
    """
    Given a dictionary with strin keys and integer values, 
    crappyhist returns a string with the histogram.

    :param d: Input dictionary.
    :param logscale: (optional) True if logscale (False by default).
    :param width: (optional) Maximum width of basrs in characters units
    :param char: (optional) Character to make the bars.
    :return: String with the histogram.
    """

    text = ""

    if logscale:
        text += "Logarithmic Scale\n"
        ratio = width / np.log10(max(d.values()))
    else:
        text += "Linear Scale\n"
        ratio = width / max(d.values())

    for key in d:
        if logscale:
            n = np.log10(d[key])
        else:
            n = d[key]
        text += f"{key:11s} ({d[key]:10d}) | {'#' * int(n * ratio)}\n"

    return text

def getstuff(filename: str, out: str ='list', header: bool = False):
    """
    Given a CSV file, it returns a generator with its rows as lists

    :param filename: Full path to the CSV file.
    :param out: (optional) Kind of yield return [list, int, chi2]
    :param header: (optional) If the file has header, skip it.
    :return: Generator of the rows as defined in out parameter.
    """

    with open(filename, "r") as csvfile:
        datareader = csv.reader(csvfile)

        if header:
            next(datareader)

        for row in datareader:
            if out == 'list':
                yield [int(row[5]), int(row[6]), int(row[7])]
            elif out == 'int':
                yield 1e6 * int(row[5]) + 1e3 * int(row[6]) + int(row[7])
            elif out == "chi2":
                yield float(row[4])
            else:
                yield row

def sort_dict(d: dict) -> dict:
    """
    Sort the dictionary by keys

    :param d: dictionary
    :return: dictionary sorted
    """

    return { key:d[key] for key in sorted(d.keys())}

def fill_histo(filename: str, cond: int = 0) -> dict:
    """
    Fills histogram into a dictionary with a CSV file

    :param filename: Full path to the dictionary
    :param cond: (ooptional) Index of the condition to fill 
        the histogram (default 0)
            * 0 -> All
            * 1 -> hits T1 = T3 = T4
            * 2 -> hits T1, T3, T4 < 5
    :return: Dictionary with histogram.
    """

    d = {}

    condition = [lambda h1, h3, h4: True,
                 lambda h1, h3, h4: h1 == h3 and h3 == h4,
                 lambda h1, h3, h4: h1 < 5 and h3 < 5 and h4 < 5]

    for h1, h3, h4 in getstuff(filename, out='list'):
        key = f"{h1:03d},{h3:03d},{h4:03d}"

        if condition[cond](h1, h3, h4):
            if key not in d:
                d[key] = 0
            d[key] += 1

    return sort_dict(d)


save_text = False

if save_text:
    equal = fill_histo(file_path, cond=1)
    minor = fill_histo(file_path, cond=2)
    with open(f"{OUT_DIR}/histos_small{file_path[-15:-4]}.txt", "w+") as outf:
        outxt = ""
        outxt += "\nEqual values (M1 == M3 == M4):\n"
        outxt += crappyhist(equal, logscale=True)
        outxt += "\n\n\nAll values (M1, M3, M4 < 5):\n"
        outxt += crappyhist(minor, logscale=True)
        outf.write(outxt)

save_png = False
if save_png:
    stuff = fill_histo(file_path, cond=0)
    hits = stuff.keys()
    counts = stuff.values()
    
    plt.figure(0)
    plt.title("All saetas")
    plt.bar(hits, counts)
    plt.xlabel('Multiplicity (M1*1e6 + M3*1e3 + M4)')
    plt.ylabel('Counts')
    plt.yscale('log')
    
    plt.savefig(f"{OUT_DIR}/histos{file_path[-15:-4]}_log.png")
    
    plt.xscale('log')
    plt.savefig(f"{OUT_DIR}/histos{file_path[-15:-4]}_loglog.png")
    
    plt.close('all')

chi_histo = True
if chi_histo:

    # plt.figure(0)
    # plt.title("Chi squared (20 bins)")
    # plt.hist([chi2 for chi2 in getstuff(file_path, out='chi2')], bins=20)
    # plt.xlabel('Chi squared')
    # plt.ylabel('Counts')
    # plt.savefig(f"{OUT_DIR}/chisto_20bins.png")

    plt.figure(1)
    plt.title("Chi squared > 30 (50 bins)")
    plt.hist([chi2 for chi2 in getstuff(file_path, out='chi2') if chi2 < 30], bins=50)
    plt.xlabel('Chi squared')
    plt.ylabel('Counts')
    plt.grid(True)
    plt.savefig(f"{OUT_DIR}/chisto_lessthan30_50bins.png")
    
    plt.figure(2)
    plt.title("Chi squared (100 bins)")
    plt.hist([chi2 for chi2 in getstuff(file_path, out='chi2')], bins=100)
    plt.xlabel('Chi squared')
    plt.ylabel('Counts')
    plt.savefig(f"{OUT_DIR}/chisto_100bins.png")
    
    # plt.xscale('log')
    # plt.close('all')

    # plt.show()
