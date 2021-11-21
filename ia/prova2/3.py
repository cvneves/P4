import pandas as pd
import numpy as np
import statistics as st
import matplotlib.pyplot as plt
from sklearn import preprocessing
from sklearn.preprocessing import RobustScaler
from sklearn.decomposition import PCA
from sklearn.model_selection import StratifiedKFold
from sklearn import tree
import seaborn as sns
from sklearn import metrics
from sklearn.metrics import confusion_matrix
from sklearn.ensemble import RandomForestClassifier

# questao 1
df = pd.read_csv('dataset/Churn_Modelling.csv', delimiter=',')
df = df.drop('CustomerId', axis=1)
df = df.drop('RowNumber', axis=1)
df = df.drop('Surname', axis=1)

df['Gender'] = preprocessing.LabelEncoder().fit_transform(df['Gender'])

fig = plt.figure()
plt.boxplot([df['EstimatedSalary'].values, df['Balance'].values])
plt.show()
fig = plt.figure()
plt.boxplot([df['Age'].values])
plt.show()
fig = plt.figure()
plt.boxplot([df['CreditScore'].values])
plt.show()

fig = plt.figure()
plt.hist(df['Geography'].values)
plt.show()

for col in [pd.get_dummies(df['Geography'])]:
	df = df.join(col)
df = df.drop('Geography', axis=1)

df['SalaryGroup'] = pd.DataFrame(pd.cut(df['EstimatedSalary'], bins=5, labels=np.arange(5), right=False))

print(df)

X = df.drop('Exited', axis=1).values
y = df['Exited'].values

skf = StratifiedKFold(n_splits=10, random_state=1, shuffle=True)

for train_index, test_index in skf.split(X,y):
	X_train, X_test = X[train_index], X[test_index]
	y_train, y_test = y[train_index], y[test_index]
	clf1 = tree.DecisionTreeClassifier(random_state=1)
	clf1.fit(X_train, y_train)
	result1 = clf1.predict(X_test)

	clf2 = RandomForestClassifier(max_depth=10, n_estimators=100, random_state=1)
	clf2.fit(X,y)
	result2 = clf2.predict(X_test)

	print(metrics.accuracy_score(y_test, result1), 
				metrics.accuracy_score(y_test, result2))

	print(confusion_matrix(y_test, result1))
	print(confusion_matrix(y_test, result2))

## questao 3
#
#df = pd.read_csv('dataset/Mall_Customers.csv', delimiter=',')
#
#df = df.drop('CustomerID', axis=1)
#df['Genre'] = preprocessing.LabelEncoder().fit_transform(df['Genre'])
#
#df = pd.DataFrame(preprocessing.MinMaxScaler().fit_transform(df.values))
#
#x = df
#
#from scipy.cluster.hierarchy import dendrogram, linkage
#from sklearn.cluster import KMeans
#from sklearn.cluster import AgglomerativeClustering
#from sklearn.metrics import pairwise_distances
#
#for n in [2,3,4]:
#	print("#######################################")
#	print("Número de clusters:", n)
#	print()
#	for link in ['single','complete']:
#		linked = AgglomerativeClustering(n_clusters=n, linkage=link).fit(df.values)
#		print("Tipo: hierárquico")
#		print("Linkagem:", link)
#		print("Silhouette score: ", metrics.silhouette_score(df.values, linked.labels_, metric='euclidean'))
#		print()
#	
#	kmeans = KMeans(n_clusters=n, random_state=0).fit(df.values)
#	print("Tipo: k-means")
#	print("Silhouette score: ", metrics.silhouette_score(df.values, kmeans.labels_, metric='euclidean'))
#	print("#######################################")
#
#
#
##from sklearn.model_selection import cross_val_score, KFold, StratifiedKFold
##from sklearn.dummy import DummyClassifier
#
##skf = StratifiedKFold(n_splits=10, shuffle=True, random_state=0)
##res 
#
#
#
##plt.figure()
##dendrogram(linked, orientation='top',distance_sort='descending', show_leaf_counts=True)
##plt.show()
