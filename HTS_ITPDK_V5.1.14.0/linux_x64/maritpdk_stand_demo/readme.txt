放到linux 目录下
cd maritpdk_stand_demo
./exec 
重新编译运行

注：需要进入lib、out目录下分别将libfixapi、libmaritpdk建立软链接，格式为ln -snf xxxx.so.n.n.n.n xxxx.so（n为版本号）

或直接进入out目录，执行./itpdk_demo直接运行