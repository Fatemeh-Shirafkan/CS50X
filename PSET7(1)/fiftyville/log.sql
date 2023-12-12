-- Keep a log of any SQL queries you execute as you solve the mystery.

-- check the crime happened description
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street"

-- find the 3 person who mentioned the name of the bakery in their words
SELECT name , transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery" ORDER BY name;

-- Finding the name of the person who withdrew money from the bank teller on the Leggett Street
SELECT name, atm_transactions.amount
    FROM people
    JOIN bank_accounts
    ON people.id = bank_accounts.person_id
    JOIN atm_transactions
    ON bank accounts.account_number = atm_transactions.account_number
    WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.transaction_type = 'withdraw';

-- Raymon said that I heard from the thief that when she was leaving,
-- she was talking to someone and told her to book the first ticket for tomorrow.
SELECT abbreviation, full_name city
    FROM airports
    WHERE city = "Fiftyville"

-- Find all flights departing Fiftyville on July 29
SELECT flights. id, full_name, city, flights. hour, flights.minute
    FROM airports
    JOIN flights
    ON airports.id = flights. destination_airport_id
    WHERE flights.origin_airport_id = (SELECT id FROM airports city = 'Fiftyville')
    AND flights. year = 2021
    AND flights.month = 7
    AND flights.day = 29
    ORDER BY flights. hour, flights. minute;

-- Check the list of flight passengers
SELECT passengers.flight_id, name, passengers.passport_number, passenger
    FROM people
    JOIN passengers
    ON people.passport_number = passengers.passport_number
    JOIN flights
    ON passengers. flight_id = flights. id
    WHERE flights. year = 2021
    AND flights.month = 7
    AND flights.day = 29
    AND flights.hour = 8
    AND flights. minute = 20
  ORDER BY passengers.passport_number

  -- We get the list of those who have a call of less than one minute on July 28
SELECT name, phone calls.duration
    FROM people
    JOIN phone calls
    ON people.phone_number = phone_calls.caller
    WHERE phone calls. year = 2021
    AND phone calls.month = 7
    AND phone_calls.day = 28
    AND phone calls.duration <= 60
  ORDER BY phone_calls.duration;

-- Get all call recipients
SELECT name, phone_calls.duration
    FROM people
    JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
WHERE phone calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration <= 60
  ORDER BY phone_calls.duration;

  -- The license plate number of the car that the Ruth said the thief came out of the
  -- Nunovai parking lot with
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
    FROM people
    JOIN bakery_security_logs
    ON people. license_plate bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.activity = 'exit'
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute >= 15
    AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;

 -- After this, we have four lists in which the name of the thief is present in all four lists