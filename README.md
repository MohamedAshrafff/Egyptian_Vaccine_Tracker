# Egyptian_Vaccine_Tracker
* An Egyptian Vaccine Tracker that allow Egyptian Residents to enter their previous doses info and track the future ones also to give them date of the upcoming dose. This Project was Done by Implementing several Data Structures in CPP after finishing the course. Mainly we used the unordered map as our hashtable to decrease the access time for indexing a user and used the Unique 14 digit key which represents the Egyptian National ID Format. 

* Implementing such a expermiment required data to display some of the Statistics used .Thus, we used Excel Sheet to read from it the data while running and saving while exiting the program which simulates a real system.

* Furthermore , our system is formatted to refresh the console to give a nice user experience even if it is on a console :)  
* Let's talk firstly  about the program Hierarchy which contains The Admin and The User and the Admin is also a user which means he as the acces to both levels.
### Registration
   * Registration for Egyptians residents only is allowed so user should only enter a full 14 number for his national id and all other info as it is seen the       Registration Photo Downwards. 
   * We Used the Governates to be within a list so that no spelling mistakes is done by the user so that it can help us in the data collection for statistics.

### Admin
* Admin have Accessiblity to delete view or move the users from the waitinglist (queue) and move him to an array list and if at the end of the deadline date to take the  dose if he have not taken it he is pushed back to the end of the waitiing list waiting for his number.

* Admins Can log in to their account only if they are approved admins and have the authenticated password which in our case is "88888888".
 
* Also Admin Can View ALL data in the  all the System (map) , waiting list and arraylist (Vector) that is done so that any deleted users if any dont interrupt the waiting list queue.  

### User 
* User have also some functionalities such as change data and delete account and display data all is done while being with the same key of the data in the map.

# ScreenShots
### Welcome Screen for starting the System
  ![Screenshot (160)](https://user-images.githubusercontent.com/96030527/170589060-64fc9cb2-5dbb-4a9f-8bc9-5cd886167783.png)
### Main Menu
  ![Screenshot (141)](https://user-images.githubusercontent.com/96030527/170589164-219cdd72-e6b4-4bcc-802a-28c49e3c1a5d.png)
### Registration 
  ![Screenshot (161)](https://user-images.githubusercontent.com/96030527/170590129-7cd693a1-e3ad-4f7c-9a79-e57457d8177b.png)
### Admin Login 
  ![Screenshot (152)](https://user-images.githubusercontent.com/96030527/170590879-0150915f-d847-4db6-b2cc-050fb450abc9.png)
   #### Admin Main Menu
   ![Screenshot (145)](https://user-images.githubusercontent.com/96030527/170591785-ef9c8718-7464-421a-8721-396dbb295172.png)
    
   #### A Random File Of The Statistics Menu
   ![Screenshot (147)](https://user-images.githubusercontent.com/96030527/170590529-42c5f652-074f-4964-9407-d4e119a9d687.png)
### User Login 
  ![Screenshot (151)](https://user-images.githubusercontent.com/96030527/170591156-a8a5f1be-fd90-4b96-8f78-815b416b558b.png)
   #### User Main Menu
   ![Screenshot (142)](https://user-images.githubusercontent.com/96030527/170591289-32f02520-35ff-470c-add6-fa86e6e44b73.png)
   #### Edit Info function
   ![Screenshot (144)](https://user-images.githubusercontent.com/96030527/170591615-cc99cf6e-0e90-4678-b0a4-2c2ad5b65198.png)
   #### Display Data Function
   ![Screenshot (143)](https://user-images.githubusercontent.com/96030527/170591583-83847fe7-40f1-44c4-8083-ec71ab70f2fc.png)
   #### Display all Users in System
   ![Screenshot 2022-05-27 010440](https://user-images.githubusercontent.com/96030527/170593442-633a4bf2-6c13-4f11-b051-217ce4c67991.png)

