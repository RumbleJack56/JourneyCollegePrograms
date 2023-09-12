import mysql.connector as mq
import PySimpleGUI as sg
import logging

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')


def checkCredentials(h="localhost",u="root",p=""):
    try:
        conn = mq.connect(host=h,user=u,password=p)
        if not conn.is_connected():
            logging.warning("Couldnt Connect")
            return False
        logging.info("Connection Made")
        return conn
    except:
        logging.warning("Mysql not working properly")
        return False

def checkForDB(conn):
    c= conn.cursor()
    c.execute("SHOW DATABASES")
    dblist = [x[0] for x in c]
    logging.debug("Database List: ",dblist)
    if "teamugv" in dblist:
        logging.debug("Team Database Found")
    else:
        c.execute("CREATE DATABASE TEAMUGV;")
        logging.debug("Team Database not found, Initialising new database")
    return dblist


