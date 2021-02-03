from bs4 import BeautifulSoup
import requests

url = 'http://www.imdb.com/chart/top'
resp = requests.get(url)
soup = BeautifulSoup(resp.text)
llist = soup.find('tbody', {'class':'lister-list'})
trs = llist.findAll('tr')
for tr1 in trs: 
    print (tr1.find('td',{'class':'titleColumn'}).text)