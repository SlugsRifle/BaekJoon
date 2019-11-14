import subprocess
i = b"10\n1 2\n1 3\n2 4\n2 5\n3 6\n4 7\n4 8\n5 9\n6 10\n1 3 6 10 2 4 8 7 5 9"

subprocess.run(['main3.py'],stdout=subprocess.PIPE,input=i)