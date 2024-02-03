#code 1

def checkPassword(password):
    
    if 8 <= len(password) <= 32:
        if password[0].isalpha():
            forbidden_chars = ['/', '\\', '=' ,"'",'"', ' ']
            if all(char not in password for char in forbidden_chars):
                return True

    return False

input_password = input()

if checkPassword(input_password):
    print("True")
else:
    print("False")


#code 2
def is_valid_password(password):

    if 8 <= len(password) <= 32:
        if password[0].isalpha():
            forbidden_chars = ['/', '\\', '=', "'", '"', ' ']
            if all(char not in password for char in forbidden_chars):
                return True


    return False


input_password = input()


if is_valid_password(input_password):
    print("True")
else:
    print("False")
