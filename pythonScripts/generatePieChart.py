import sys
import matplotlib

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
    df.drop(len(df) - 1, inplace=True)
    explode = np.full(len(df), 0.1)

    plt.figure(0)
    loc_total = sum(df['code'])
    plt.pie(x=df['code'], labels=None, explode=explode, wedgeprops={
            'edgecolor': 'b', 'linewidth': 1}, autopct=lambda p: '{:.0f}'.format(p * loc_total / 100))
    plt.legend(df['language'])
    plt.title('Lines of code')

    plt.figure(1)
    comments_total = sum(df['comments'])
    plt.pie(x=df['comments'], labels=None, explode=explode,
            wedgeprops={'edgecolor': 'b', 'linewidth': 1}, autopct=lambda p: '{:.0f}'.format(p * comments_total / 100))
    plt.legend(df['language'])
    plt.title('Comments')

    plt.figure(2)
    blanks_total = sum(df['blanks'])
    plt.pie(x=df['blanks'], labels=None, explode=explode,
            wedgeprops={'edgecolor': 'b', 'linewidth': 1}, autopct=lambda p: '{:.0f}'.format(p * blanks_total / 100))
    plt.legend(df['language'])
    plt.title('Blanks')

    plt.show()
