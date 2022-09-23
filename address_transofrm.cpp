// There are two strings N and A representing name and address, respectively. Name consists of only lowercase English characters. The address consists of lowercase English characters and digit. You can replace each digit of address string by a substring consisting of lowercase English characters or empty string. After replacing, determine if the string address can be transformed into the string name or not.

// Conditions of the substring

// The length of such a substring should not be greater than the digit value.
// The length of the substring should be in range (0,digitvalue) inclusive.
// Finally, after replacing the digit with the substring, String A should match with the string N.
// For example, if address = “a22fg”, then you can replace the two “2”’s by “bc” and “de”, respectively. So, address can be transformed into “abcdefg”.

// Constraints

// The lengths of the name and address are n and m, respectively.

// 1≤T≤1000
// 1≤n≤1000
// 1≤m≤1000
// Input Format

// The first line contains a single integer T —- the number of test cases.
// For each testcase:
// The first line contains two integers n, m —- the lengths of name and address, respectively.
// The second line contains a string name of length n.
// The third line contains a string address of length m.
// Output Format

// For each Testcase, output "YES" if the string address can be transformed into the string name. Otherwise, output "NO".

// Sample Input

// 2

// 4 1

// abcd

// 9

// 4 3

// abcd

// ac9

// Sample Output

// YES

// NO

// Explanation

// In the first testcase, you can replace the digit character "9" of A by "abcd", because the length of "abcd" is less than 9.

// In the second testcase, there is no way to transform the string A into N.

// Example test Case:

// 2

// 4 1

// abcd

// 9

// 4 3

// abcd

// ac9

// Output

// YES

// NO

// steps:
// 1. read the number of test cases
// 2. read the length of name and address
// 3. read the name and address
// 4. check if the address can be transformed into name or not
// 5. print the result
// 6. end

// algorithm to check if address can be transformed into name or not
// 1. if the address contains only string and string is equal to name then return true else return false
// 2. if the address contains only digit and digit is equal to length of name then return true else return false
// 3. if the address contains both string and digit then
// 4.     compare all the characters of address before the first digit with the characters of name
// 5.     if the characters are not equal then return false
// 6.     else
// 7.         compare all the characters of address after the last digit with the characters of name
// 8.         if the characters are not equal then return false
// 9.         else
// 10.             for every digit in address
// 11.                 if the digit is 0 then
// 12.                     if the length of substring is not equal to 0 then return false
// 13.                 else
// 14.                     if the length of substring is greater than the digit then return false
// 15.             return true
// 16. end

// code
