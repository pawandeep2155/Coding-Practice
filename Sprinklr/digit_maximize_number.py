    # 9 digits 1 -9, each having some cost, need to make maximum number using these digits with given amount,
    
total_money = 2   

cost_of_digit = [9, 11, 1, 12, 5, 8, 9, 10, 6]

# Appending the list digits with [weight, number] 
k=1
digits=list()

for i in cost_of_digit:
    digits.append([i,k])
    k+=1

#  Discarding any digits that cost more than a bigger digit: (because it's never a good idea to pick that one instead of a cheaper digit with a bigger value)
i = 8
while(i>0):
    if digits[i][0] <= digits[i-1][0]:
        del digits[i-1]
        i-=1
    else:
        i-=1

# Sorting the digits based on weight
digits.sort(key=lambda x:x[0],reverse=True)

max_digits = total_money//digits[-1][0] # Max digits that we can have in ANSWER
selected_digit_weight = digits[-1][0] 

ans=list()

if max_digits > 0:
    for i in range(max_digits):
        ans.append(digits[-1][1])

# Calculating extra money we have after the selected digits
extra_money = total_money % digits[-1][0]

index = 0

# Sorting digits in Descending order according to their value
digits.sort(key=lambda x:x[1],reverse=True)

while(extra_money >= 0 and index < max_digits):
    temp = extra_money + selected_digit_weight # The money we have to replace the digit
    swap = False # If no digit is changed we can break the while loop 
    
    for i in digits:
        # Checking if the weight is less than money we have AND the digit is greater than previous digit
        if i[0] <= temp and i[1] > digits[-1][1]: 
            ans[index] = i[1]
            index += 1
            extra_money = temp - i[0]
            swap = True
            break
    if(not swap):
        break

if len(ans) == 0:
    print("Number cannot be formed")
else:
    for i in ans:
        print(i,end="")
    print()