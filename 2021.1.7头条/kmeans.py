import numpy as np
import random

INF = 1000000000

def distance(p1, p2):
    return np.sqrt(((p1 - p2)**2).sum())

def kmeans(points, k):
    centers = random.sample(list(points), k)
    eps = 1e-6
    center_dis = INF
    while center_dis > eps:
        print("center_dis=", center_dis)
        clusters = []
        for i in range(k):
            clusters.append([])
        for point in points:
            min_dis = INF
            min_idx = -1
            for i, center in enumerate(centers):
                dis = distance(point, center)
                if dis < min_dis:
                    min_dis = dis
                    min_idx = i
            clusters[min_idx].append(point)
        new_centers = []
        for cluster in clusters:
            new_center = np.mean(cluster, axis=0)
            new_centers.append(new_center)
        new_centers = np.array(new_centers)
        center_dis = np.sqrt(((new_centers - centers)**2).sum())
        print("after center_dis=", center_dis)
        centers = new_centers
    return clusters
    
                    
    

points = np.array([[0,0],[1,2],[3,1],[8,8],[9,10],[10,7]])
k = 2
clusters = kmeans(points, k)
for cluster in clusters:
    print(cluster)

          
    
    
