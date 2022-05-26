from matplotlib import pyplot as plt
import pandas as pd
import matplotlib.cm as cm
import warnings
warnings.filterwarnings('ignore')
warnings.warn('DelftStack')
warnings.warn('Do not show this message')
print("")

fig = plt.figure(figsize=(15,10))
data = pd.read_csv ('data.csv') 
labels1 = ['Fever','Fatigue','Diarrhea','Muscle pain','None']
labels2 = ['Astrazeneca', 'Sinopharm','Pfizer','Moderna','Johnson & Johnson','Sinovac','Sputnik','Other']
sideeffect1=[]
for i in range(len(labels2)):
   sideeffect1.append(data.loc[(data['Vaccine Type'] == labels2[i])&(data['Side Effect']=='Fatigue')].count()[0])
   
plt.bar(labels2,sideeffect1,color=cm.get_cmap("Pastel2").colors)
plt.ylabel('Number of people who suffered from fatigue')
plt.xlabel('Vaccine Type')
plt.title('Highest vaccine causing fatigue')
plt.tight_layout()
plt.show()