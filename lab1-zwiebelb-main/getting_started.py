secret = 42
guess = 0
tries = 0
while secret != guess:
	guess = int(input("\nPlease enter a random number: "))
	if guess == secret:
		print("You guessed correctly!")
	elif guess > secret:
		print("Wrong! Your value is larger than the secret number.")
	elif guess < secret:
		print("Wrong! Your value is lower than the secret number.")
	tries += 1
print("\nNumber of tries it took to guess the correct number:",tries)
