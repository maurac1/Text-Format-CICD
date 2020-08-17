*** Setting ***
Documentation    This is for ASSET Demo
Library    BuiltIn
Library    OperatingSystem


*** Variable ***


*** Keywords ***
File Should Contain
     [Arguments]    ${filename}    ${demo}
     ${filecontents} =    Get File    ${filename}
     Should Contain    ${filecontents}    ${demo}


*** Test Cases ***
Test If File Contains Content
     File Should Exist      contacts.txt
     File Should Contain    contacts.txt    Bobby
     File Should Contain    contacts.txt    King
     File Should Contain    contacts.txt    Maura
     File Should Contain    contacts.txt    Choudhary
     File Should Contain    contacts.txt    Alec
     File Should Contain    contacts.txt    Parsons
     File Should Contain    contacts.txt    Nicole
     File Should Contain    contacts.txt    Peck
				    