
import matplotlib.pyplot as plt
import pandas as pd
import warnings
warnings.filterwarnings('ignore')
warnings.warn('DelftStack')
warnings.warn('Do not show this message')
print("")

plt.style.use("fivethirtyeight")
data = pd.read_csv('data.csv')
fig = plt.figure(figsize=(11,5))
fig.patch.set_facecolor('blanchedalmond')
plt.rcParams['text.color'] = 'black'

male = data.loc[data['Gender'] == 'm'].count()[0]
female = data.loc[data['Gender'] == 'f'].count()[0]    
labels = ['Female', 'Male']
colors = ['palevioletred', 'cornflowerblue']
plt.pie([male,female],labels=labels,colors=colors,autopct='%0.2f%%'
        ,shadow=True,
        wedgeprops=
        { 'linewidth' : 1, 'edgecolor' : "black" },startangle=140)

plt.title('Percentage of females and males registered in the system',y=0.97)
plt.tight_layout()
plt.show()