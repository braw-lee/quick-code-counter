# type: ignore
import sys

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


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

    # set load csv file
    data = loadCsvData(sys.argv)
    # use pandas.DataFrame for easier graph plotting
    df = pd.DataFrame(data)
    ax = df.plot.bar(y=['comments', 'code', 'blanks'],
                     color=['purple', 'cyan', 'red'], linewidth=2, edgecolor='b', rot=45)
    plt.legend(['Comments', 'LOC', 'Blanks'])
    plt.xlabel('Languages')
    plt.ylabel('Lines')

    for container in ax.containers:
        ax.bar_label(container, label_type='edge')

    # set labels for x axis
    x_axis = np.arange(len(df))
    plt.xticks(ticks=x_axis, labels=df["language"])

    plt.tight_layout()
    plt.show()
