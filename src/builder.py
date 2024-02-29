import os,sys
base_path = __file__
base_path = base_path.replace("\\","/").removesuffix("builder.py")
for _,__,path in os.walk(base_path):
    for file in path:
        if(file=="builder.py"): continue
        cmd = f"g++ -c {base_path+file} -o {base_path+file.removesuffix(".cpp")+".o"}"
        # print(cmd)
        os.system(cmd)