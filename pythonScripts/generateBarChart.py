# type: ignore
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import sys


def loadCsvData(argv):
    '''
    Function to load csv data from a hardcode csv file path
    '''
    if (len(argv) != 2):
        raise RuntimeError(
            "Invalid usage, this python scrits accepts one CLI argument, i.e name of csv file")
    csv_file = sys.argv[1]
    return pd.read_csv(csv_file)


if __name__ == '__main__':
    plt.style.use("seaborn-v0_8-poster")

    data = loadCsvData(sys.argv)
    df = pd.DataFrame(data)

    Y_axis = np.arange(len(df))

    # set bar height
    height = 0.2

    # plot comments bars
    plt.barh(y=Y_axis - height, width=df["comments"],
             color='red', height=height, label="Comments", linewidth=2, edgecolor='b')
    # plot LOC bars
    plt.barh(y=Y_axis, width=df["code"], color='cyan',
             height=height, label="LOC", linewidth=2, edgecolor='b')
    # plot blanks bars
    plt.barh(y=Y_axis + height, width=df["blanks"],
             color='purple', height=height, label="Blanks", linewidth=2, edgecolor='b')

    # set labels for y axis
    plt.yticks(ticks=Y_axis, labels=df["language"])
    plt.title('QCC Data')
    plt.xlabel('Languages')
    plt.ylabel('Lines')
    plt.legend()
    plt.autoscale(enable=True, axis='y', tight=True)  # tight layout

    plt.show()
