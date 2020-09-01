import os
for filename in os.listdir():
	if filename.endswith('.hpp'):
		base=filename[:-4]
		dest=base+'.sublime-snippet'
		with open(dest,'w') as f:
			f.write('<snippet>\n\t<content>\n\t<![CDATA[\n')
			with open(filename,'r') as f1:
				f.write(f1.read())
			f.write(f']]>\n\t</content>\n\t<tabTrigger>_{base}</tabTrigger>\n</snippet>\n')
