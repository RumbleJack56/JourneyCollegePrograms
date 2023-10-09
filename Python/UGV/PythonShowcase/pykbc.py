import tkinter
from bs4 import BeautifulSoup
import time
import requests

def acquireQuestions():
    """Queries the Internet and sends a dictionary of genre and 2d array of question answer as key value pair"""
    browser = requests.get("")
    code = BeautifulSoup(browser)
    print(code)

acquireQuestions()
