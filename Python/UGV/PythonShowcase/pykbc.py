import tkinter
from bs4 import BeautifulSoup
import time
import requests

def acquireQuestions():
    """Queries the Internet and sends a dictionary of genre and 2d array of question answer as key value pair"""
    browser = requests.get("https://rjxdatascrapper.netlify.app/")
    code = BeautifulSoup(browser.content,"lxml")
    val = code.findAll(attrs={"class":"topic"})
    print(code.prettify())
    if val==None:
        return -1
    for qset in val:
        topicname = qset.find(attrs={"class":"tname"})
        print(topicname.getText())
        

acquireQuestions()
