from tkinter import Button
from sqlFuncs import *
import PySimpleGUI as sg
import logging
"""
Project Basics

Functions --> Windows
Window:
    --> theme
    --> layout
    --> initialiser
    --> while loop for polling for data

Window 1 : MySQL connectivity
    --> auto mode
    --> Input host, user , pass and manual connect
    --> exit button





"""

#using logging instead of printing
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')
#team UGV mysql server with gui

#prebuilt theme for colors
sg.theme("DarkBlue2")

#first we make a connection window
def sqlConnWindow():
    #matrix for the look of the page
    wFormat =[[sg.Text("TEAM UGV")],
            [sg.Text("MySQL Connectivity")],
            [sg.Text("Connection Status:"),sg.Text("\"Not Connected\""),sg.Button("Autoconnect")],
            [sg.Text("Host: "),sg.Input(key="host",font=("Calibri",14))],
            [sg.Text("User: "),sg.Input(key="user",font=("Calibri",14))],
            [sg.Text("Pass: "),sg.Input(key="pass",font=("Calibri",14))],
            [sg.Button("Login"),sg.Exit()],]


    #window initialiser
    window = sg.Window("SQL Project",wFormat,size=(800,640),font=("Eras Bold ITC",20),resizable=True)
    
    #actually start the window and poll for input
    while True:
        event , values = window.Read()

        #input log
        logging.debug([event,values])

        #if window closed or exit pressed
        if event in (sg.WINDOW_CLOSED,"Exit"): break
        #connection procedure for manual or auto mode
        if event in ("Login","Autoconnect"):
            global conn
            #manual connection for custom sql user
            if event == "Login":
                conn = checkCredentials(values["host"],values["user"],values["pass"])

            #auto mode in action takes default parameters
            conn = checkCredentials()

            #error management
            if conn == False: 
                sg.popup_error("No Connection Established, Wrong Crendentials, Try Again")
            #if connection is made it closes old window proceeds to new window
            else: 
                window.close()
                #presence test for tables and creating if non-existent
                sg.popup("Searching Database",title="Searching Database",auto_close=True,auto_close_duration=1)
                checkForDB(conn)
                mainWindow()
    window.close()
    
def mainWindow():
    wFormat=[[sg.Image("ugv.png"),sg.Text("TEAM UGV")],
            [sg.Text("Team Members")],
            [sg.Text("Projects List")],
            [sg.Text("Sponsorship Status")],
            [sg.Text("Funding")],
            [sg.Text("New recruits")],
            [sg.Button("Back"),sg.Exit()]]
    
    window = sg.Window("SQL Project",wFormat,size=(800,640),font=("Eras Bold ITC",20),resizable=True)

    while True:
        event , values = window.Read()

        #input log
        logging.debug([event,values])

        #if window closed or exit pressed
        if event in (sg.WINDOW_CLOSED,"Exit"): break
        #connection procedure for manual or auto mode
        if event in ("Back"):
            window.close()
            sqlConnWindow()
    window.close()


sqlConnWindow()
