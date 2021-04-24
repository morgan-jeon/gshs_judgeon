import sys
import os
import requests

while True:
	name = input("? ")
	f = open(f'{name}.md','w')
	f.write(f"Question {name}\n------------------------\n\n------------------------\nAnswer\n------------------------\n\n------------------------")