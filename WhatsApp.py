from selenium import webdriver
import sys
browser = webdriver.Chrome()
browser.get('https://web.whatsapp.com/') 
Contact_Name = sys.argv[1]
print(Contact_Name) 
Message = sys.argv[2]
print("Press Any Key To Send Message...")
print("Sending Your Message...")
print("Sending Your Message...")
print("Sending Your Message...")
Required_Contact = browser.find_element_by_xpath('//span[@title = "{}"]'.format(Contact_Name)) 
Required_Contact.click()
Message_Typer = browser.find_element_by_class_name('_1Plpp')
Message_Typer.send_keys(Message)
Send = browser.find_element_by_class_name('_35EW6')
Send.click()
print("Message Sent")
