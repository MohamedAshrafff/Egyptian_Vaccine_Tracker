import matplotlib.pyplot as plt
import pandas as pd
import warnings
warnings.filterwarnings('ignore')
warnings.warn('DelftStack')
warnings.warn('Do not show this message')
print("")

plt.style.use("fivethirtyeight")
data = pd.read_csv('data.csv')
fig = plt.figure(figsize=(8,5))
fig.patch.set_facecolor('darkslategray')
plt.rcParams['text.color'] = 'cornsilk'
have_taken = data.loc[data['Second Dose'] == 1].count()[0]
have_not_taken_yet = data.loc[data['Second Dose'] == 0].count()[0]
labels = ['have taken', 'have not taken yet']
colors = ['darkgray', 'slategray']

plt.pie([have_taken,have_not_taken_yet],labels=labels,colors=colors,autopct='%0.2f%%'
        ,shadow=True,
        wedgeprops=
        { 'linewidth' : 1, 'edgecolor' : "black" },startangle=140)
plt.tight_layout()
plt.title('Percentage of second dose',y=0.97)
plt.show()