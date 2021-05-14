import requests

def submit(req, submit_dict):
	url = 'http://judgeon.net/submit.php'

	for su in submit_dict.keys():
		dict_data = {'id':su,'language':'1','source':submit_dict[su],'csrf':''}

		response = req.post(url=url, data=dict_data, headers={'Content-Type': 'application/x-www-form-urlencoded','Cookie':'PHPSESSID=5ise9ata42likdrfqau0v9u967'})

		if response.status_code == 200:
			print(f'Problem id {su} Submitted')
		# print(response.content.decode())

def login(req):
	url = 'http://judgeon.net/login.php'

	dict_data = {'user_id':'gshs363315','password':'979f8a033625f761b3ef4807bce2a837','submit':'','csrf':''}

	response = req.post(url=url, data=dict_data, headers={'Content-Type': 'application/x-www-form-urlencoded','Cookie':'PHPSESSID=5ise9ata42likdrfqau0v9u967'})

	if response.status_code == 200:
		print("Login Succeed")


if __name__=="__main__":
	s = requests.Session()
	login(s)
	submit_dict = {'2010':'''
	#include <cstdio>
	#include <stack>

	int main(){
	    int n, r=0;
	    scanf("%d",&n);
	    std::stack<int> s;
	    for(int i=0,tmp;i<n;i++){
	    	scanf("%d", &tmp);
	    	s.push(tmp);
	    }
	    int tmp;
		while(!s.empty()){
			if(tmp>s.top()){
				r-=s.top();
			}
			else {
				r+=s.top();
			}
			tmp=s.top();
	        s.pop();
	    }
	    printf("%d", r);
	}
	'''}
	submit(s, submit_dict)