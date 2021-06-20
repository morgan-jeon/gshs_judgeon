import sys, os
import requests
import hashlib
import time

option = {'-s':'submit', '-l':'login', '-c':'check'}

def login(argv: list, req):
    id = argv[0]
    pw = argv[1]

    url = 'http://judgeon.net/login.php'

    dict_data = {'user_id':id,'password':hashlib.md5(pw.encode()).hexdigest(),'submit':'','csrf':''}

    response = req.post(url=url, data=dict_data, headers={'Content-Type': 'application/x-www-form-urlencoded'})

    if response.status_code == 200:
        print("Login Succeed")

    with open(".data", 'w') as f:
        f.write(f"{id},{pw}")

def getSess(req):
    with open(".data", 'r') as f:
        pwf = f.read()
        id = pwf.split(',')[0]
        pw = pwf.split(',')[1]

    url = 'http://judgeon.net/login.php'

    dict_data = {'user_id':id,'password':hashlib.md5(pw.encode()).hexdigest(),'submit':'','csrf':''}

    response = req.post(url=url, data=dict_data, headers={'Content-Type': 'application/x-www-form-urlencoded'})

    if response.status_code == 200:
        print("Login Succeed")

def submit(argv: list, req):
    pid = argv[0]
    filename = argv[1]

    with open(filename, 'r') as f:
        code = f.read()

    url = 'http://judgeon.net/submit.php'

    dict_data = {'id':pid,'language':'1','source':code,'csrf':''}

    response = req.post(url=url, data=dict_data, headers={'Content-Type': 'application/x-www-form-urlencoded'})

    if response.status_code == 200:
        time.sleep(1)
        sid = int(response.content.decode().split('<td>')[1].split('</td>')[0])
        print(f'Problem id {pid} Submitted as {sid}')
        check([sid], req)
        
def check(argv: list, req):
    sid = argv[0]
    checku = f'http://judgeon.net/showsource.php?id={sid}'
    check = req.get(checku).content.decode().split('**************************************************************')[1]
    print(check)

    if 'Compile Error' in check:
        ceinfo = f'http://judgeon.net/ceinfo.php?sid={sid}'
        errtxt = req.get(ceinfo).content.decode().split("id='errtxt' >")[1].split('</pre>')[0]
        print('Explain:\n' + requests.utils.unquote(errtxt))

if __name__=="__main__":
    if(len(sys.argv) == 1):
        print("""Usage: Submit: -s [problem id] [filename] Login: -l [id] [pw] Check: -c [sid]""")
        sys.exit()
    
    s = requests.Session()
    if option[sys.argv[1]] != 'login':
        getSess(s)

    globals()[option[sys.argv[1]]](sys.argv[2:], s)