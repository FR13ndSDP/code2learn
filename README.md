# code2learn
## BASH
### <font color = blueoran> \#193 Valid Phone Numbers </font>

Given a text file `file.txt` that contains list of phone numbers (one per line), write a one liner bash script to print all valid phone numbers.

You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

You may also assume each line in the text file must not contain leading or trailing white spaces.

Example:

Assume that `file.txt` has the following content:

>987-123-4567 
>123 456 7890 
>(123) 456-7890

Your script should output the following valid phone numbers:

>987-123-4567 
>(123) 456-7890

<font color= orange size = 4> Solved:</font>

`grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt` 

`grep -E "^(\([0-9]{3}\) |^[0-9]{3}-)[0-9]{3}-[0-9]{4}$" file.txt` 

`sed -n -E '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt`

### <font color = blueoran> \#195 Tenth Line </font>
Given a text file file.txt, print just the 10th line of the file.

Example:

Assume that file.txt has the following content:

> Line 1 
> Line 2 
> Line 3 
> Line 4 
> Line 5 
> Line 6 
> Line 7 
> Line 8 
> Line 9 
> Line 1 

Your script should output the tenth line, which is:
> Line 10

Note:
1. If the file contains less than 10 lines, what should you output?
2. There's at least three different solutions. Try to explore all possibilities.

<font color= orange size = 4> Solved:</font>

`awk 'NR==10' file.txt`

NR==10 to match the 10th line

`tail -n +10 file.txt | head -n1`

tail -n +10 print from 10th line， head -n1 made only first line output 

`sed -n '10p' file.txt`

sed match 10th line, without considering it might be less than 10

```bash
#!/bin/bash 
row_num=$(cat file.txt | wc -l)  # or grep -c "" file.txt 
#echo $row_num  
if [ $row_num -lt 10 ];then  
   echo "The number of row is less than 10"  
else 
   awk '{if(NR==10){print $0}}' file.txt  
fi  
```
consider file might be less than 10 lines ,should print a message.


### <font color = blueoran> \#192 Word Frequency </font>

Write a bash script to calculate the frequency of each word in a text file words.txt.

For simplicity sake, you may assume:

- `words.txt` contains only lowercase characters and space ' ' characters.
- Each word must consist of lowercase characters only.
- Words are separated by one or more whitespace characters.
Example:

Assume that `words.txt` has the following content:

> the day is sunny the the
> the sunny is is

Your script should output the following, sorted by descending frequency:

> the 4
> is 3
> sunny 2
> day 1

Note:
1. Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
2. Could you write it in one-line using Unix pipes?

<font color= orange size = 4> Solved:</font>



### <font color = blueoran> \#194 Transpose File </font>
Given a text file `file.txt`, transpose its content.

You may assume that each row has the same number of columns and each field is separated by the `' ' `character.

Example:

If file.txt has the following content:

> name age
> alice 21
> ryan 30

Output the following:

> name alice ryan
> age 21 30

