import matplotlib.pyplot as plt
import matplotlib.cm as cm
import pandas as pd
import warnings
warnings.filterwarnings('ignore')
warnings.warn('DelftStack')
warnings.warn('Do not show this message')
print("")

plt.style.use("fivethirtyeight")
data = pd.read_csv('data.csv')
fig = plt.Figure(figsize=(12,5))
fig.patch.set_facecolor('floralwhite')
plt.rcParams['text.color'] = 'black'
labels = ['Astrazeneca', 'Sinopharm','Pfizer','Moderna','Johnson & Johnson','Sinovac','Sputnik','Other']
Vaccine=[]
for i in range(len(labels)):
 Vaccine.append(data.loc[data['Vaccine Type'] == labels[i]].count()[0])
 
plt.barh(labels,Vaccine,color=cm.get_cmap("Pastel1").colors)
plt.xlabel('Total number of people')
plt.ylabel('Vaccine Type')
plt.title('Highest taken vaccine type')
plt.tight_layout()
plt.show()