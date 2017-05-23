#!/home/kirill/anaconda3/bin/python
import os

gv_files = os.listdir('../gv_files/')
# for f in ./*.gv; do dot -Tgif $f -o $f.gif; done;
for item in gv_files:
    if item.endswith('.gv'):
        os.system('dot -Tgif ../gv_files/{} -o ../images/{}.gif'.format(item, item))
