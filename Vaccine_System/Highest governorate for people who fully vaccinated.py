from matplotlib import pyplot as plt
import pandas as pd
import matplotlib.cm as cm
import warnings
warnings.filterwarnings('ignore')
warnings.warn('DelftStack')
warnings.warn('Do not show this message')
print("")

plt.figure(figsize=(15,5))
data = pd.read_csv ('data.csv') 
labels = ['Alexandria','Aswan','Asyut','Beheira','Cairo','Dakahlia','Damietta','Faiyum','Gharbia','Giza','Ismailia','Luxor','Matruh','Minya','Monufia'
          ,'New Valley','North Sinai','Port Said','Qalyubia','Qena','Red Sea','Sharqia','Sohag','South Sinai','Suez','Kafr El Sheikh']
fullyvaccinated1=[]
for i in range(len(labels)):
 fullyvaccinated1.append(data.loc[(data['Second Dose'] == 1)&(data['Governorate']==labels[i])].count()[0])
 
plt.bar(labels,fullyvaccinated1,color=cm.get_cmap("Pastel2").colors)
plt.xlabel('Governorates')
plt.ylabel('Total number of fully vaccinated people')
plt.xticks(rotation=90)
plt.title('Highest governorate for fully vaccinated people')
plt.tight_layout()
plt.show()