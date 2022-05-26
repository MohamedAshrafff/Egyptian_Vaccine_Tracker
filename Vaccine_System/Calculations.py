import pandas as pd
import warnings
warnings.filterwarnings('ignore')
warnings.warn('DelftStack')
warnings.warn('Do not show this message')
print("")

data = pd.read_csv ('data.csv') 
 
sum1 = data['First Dose'].sum()
females = data.loc[data['Gender'] == 'f'].count()[0]
males = data.loc[data['Gender'] == 'm'].count()[0]
gender=females+males
sum2 = data['Second Dose'].sum()
sum3=gender
print('Total number of users in the system:', sum3)
average_ages=data['Age'].mean()
Nsideeffect1=[]
Vaccine=[]
labels2 = ['Astrazeneca', 'Sinopharm','Pfizer','Moderna','Johnson & Johnson','Sinovac','Sputnik','Other']
for i in range(len(labels2)):
 Vaccine.append(data.loc[data['Vaccine Type'] == labels2[i]].count()[0])
print('\nSafety rate for every vaccine type:')
for i in range(len(labels2)):
   Nsideeffect1.append(data.loc[(data['Vaccine Type'] == labels2[i])&(data['Side Effect']=='None')].count()[0])
   y = "{:.2f}"
   print(y.format(((Nsideeffect1[i]/Vaccine[i])*100)), "% ", labels2[i])
   
x = "\nPercentage of the first dose: {:.2f}"
print (x.format((sum1/sum3)*100), '%')

x = "Percentage of the both doses: {:.2f}"
print(x.format((sum2/sum3)*100), '%')

x = "Percentage of females: {:.2f}"
print (x.format((females/gender)*100), '%')

x = "Percentage of males: {:.2f}"
print (x.format((males/gender)*100), '%')

x = "\nAverage of ages who registered in system: {:.0f}"
print (x.format((average_ages)), 'years old')