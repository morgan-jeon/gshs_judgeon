import requests
import time

def submit(req, submit_dict, delay):
	url = 'http://judgeon.net/submit.php'

	for su in submit_dict.keys():
		dict_data = {'id':su,'language':'1','source':submit_dict[su],'csrf':''}

		time.sleep(delay)

		response = req.post(url=url, data=dict_data, headers={'Content-Type': 'application/x-www-form-urlencoded','Cookie':'PHPSESSID=5ise9ata42likdrfqau0v9u967'})

		if response.status_code == 200:
			print(f'Problem id {su} Submitted')
		# print(response.content.decode())

def login(req):
	url = 'http://judgeon.net/login.php'

	# dict_data = {'user_id':'gshs363315','password':'979f8a033625f761b3ef4807bce2a837','submit':'','csrf':''}
	
	dict_data = {'user_id':'testtesttest','password':'05a671c66aefea124cc08b76ea6d30bb','submit':'','csrf':''}

	response = req.post(url=url, data=dict_data, headers={'Content-Type': 'application/x-www-form-urlencoded','Cookie':'PHPSESSID=5ise9ata42likdrfqau0v9u967'})

	if response.status_code == 200:
		print("Login Succeed")


if __name__=="__main__":
	s = requests.Session()
	login(s)
	submit_dict = dict()
	f = open('ac-gshs361508.txt','r',-1,'utf-8')
	while 1:
		a = f.readline()
		# print(a)
		if not a: 
			break
		if 'Problem' in a:
			pid = int(a.replace('Problem','').replace(':',''))
			print(f'{pid}')
			submit_dict[pid] = ''
		elif '-------' not in a:
			submit_dict[pid] = submit_dict[pid] + a

	print(len(submit_dict))
	submit(s, submit_dict, 1)