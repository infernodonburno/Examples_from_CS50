''' Censors the words for the text file "banned.txt" 

    by Chris Purnell 
 '''

import cs50
from sys import argv


def main():

    # checks for two arguments in command line
    if len(argv) != 2:
        print("Usage for python bleep.py dictionary")
        exit(1)

    # gets user input, splits and strips user input
    message = cs50.get_string("What message would you like to censor? ").strip()

    message = message.split(" ")

    # creates an empty set to store banned words in
    censored = set()

    # opens text file and adds them to the list while stripping the end lines
    with open(argv[1]) as file:
        for line in file:
            censored.add(line.strip("\n"))

        # iterates over the words in message
        for i in message:

            # declare and set to 0
            count = 0

            for j in censored:

                # if badword found, increments count
                if i.lower() in j:

                    count += 1

                    # sets length for * to be printed, set to lower because of damn DARN error
                    n = len(j)

            # if badword found, replace letters with * by length of word
            if count == 1:

                print(j.replace(j, "*" * n), end=" ")

            # if not bad, just print the word regularly
            else:

                print(i, end=" ")

        print()


if __name__ == "__main__":
    main()
