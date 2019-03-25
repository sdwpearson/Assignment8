i = 1;

with open("subjobs", "w+") as output_file:	
	for length in range(100,350,50):
		for seed in range(1,41):
			output_file.write("./antsontable --netcdf_output_steps=0 --screen_output_steps=0 --length=%d --seed=%d; echo \"Job %d Done\" \r\n" %(length, seed, i)) 
			i = i + 1;
output_file.close()

