i = 1;

with open("subjobs", "w+") as output_file:	
	for length in range(100,350,50):
		for seed in range(1,41):
			#length = i/50*50+100
			#seed = i%40+1
			output_file.write("mkdir -p serialjobdir%d && cd serialjobdir%d && ../antsontable --filename=ants%d.nc --length=%d --seed=%d;\r\n" %(i, i, i, length, seed)) 
			i = i + 1;
output_file.close()

