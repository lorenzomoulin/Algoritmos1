def dif_div(x, y, ordem):
	matrix = [y]
	for k in range(1,ordem + 1,1):
		matrix.append([(matrix[k-1][i+1] - matrix[k-1][i])/(x[i+k] - x[i]) for i in range(len(matrix[k-1])-1)])
	return matrix
	
print(dif_div([0.0,1.0,2.5,3.75,5.0,6.250,7.5,7.8,8.0],[1.1,1.24,1.9750,3.068750,4.6000, 6.568750,8.97500,9.6176000,10.0600000],8))
