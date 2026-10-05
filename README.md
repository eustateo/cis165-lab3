# Lab 3: C++ Output and Time Calculations

Course section: CIS-165-W099

## Plans and decisions

For the diamond, my first idea was a loop that increased the stars by two
until seven and then decreased them. AI pointed out that this lab does not
allow loops. Before the code draft, I changed my plan: print strings with
spaces and stars, then move to the next line. The program uses seven separate
output statements.

For the time program, I needed AI to explain the problem. The plan developed
with that help was to store the two times, convert each into hours and minutes,
subtract the total minutes to find the extra time, convert that difference,
and print the stored answers. This was an AI-assisted plan, not a plan I had
already developed independently.

After running the first version, I asked for shorter variable names because
the original names were too long. The final names keep the level and units
visible, such as `level1_minutes` and `level1_hours`. `extra_minutes` stores
the difference between the levels.

## Compile and run

Open https://www.onlinegdb.com/online_c++_compiler and select C++. Copy one
source file into the editor, replacing the sample code, then click **Run**.
Each file has its own `main` function, so run the programs separately.
Compare each output with the calculations recorded before running. For a
changed-value test, edit the two starting minute values and run again.
Restore 78 and 144 before downloading the final `game_time.cpp` source.

Terminal alternative, from this directory:

```sh
g++ -std=c++17 -Wall -Wextra diamond.cpp -o diamond
./diamond
g++ -std=c++17 -Wall -Wextra game_time.cpp -o game_time
./game_time
```

## Tests

### Diamond

I ran the diamond program in OnlineGDB and confirmed the shape was correct.
At first I thought spaces were needed after the stars too. With AI's
explanation, I realized the spaces are needed only at the start of each line.
The leading spaces position the stars, and each newline starts the next row.

The required pattern has these counts. The counts below describe the code
and assignment; AI helped identify them.

| Line | Leading spaces | Stars |
| --- | --- | --- |
| 1 | 3 | 1 |
| 2 | 2 | 3 |
| 3 | 1 | 5 |
| 4 | 0 | 7 |
| 5 | 1 | 5 |
| 6 | 2 | 3 |
| 7 | 3 | 1 |

### Assigned time values

Before running, I calculated that 78 minutes is 1 hour and 18 minutes, and
144 minutes is 2 hours and 24 minutes. For the difference, I accidentally
used 77 instead of 78. AI corrected the calculation to 144 - 78 = 66 minutes,
or 1 hour and 6 minutes. This correction happened before the run.

I ran the program and reported:

```text
Level 1: 1 hours and 18 minutes
Level 2: 2 hours and 24 minutes
Level 2 took longer by: 1 hours and 6 minutes
```

### Changed values

I first changed the values to 85 and 157 and clicked Run. The output was
1 hour and 25 minutes, 2 hours and 37 minutes, and an extra 1 hour and
12 minutes. I did not calculate independent predictions before that run.

For a fresh test, I recorded these predictions before running:

| Values | Expected Level 1 | Expected Level 2 | Expected extra time |
| --- | --- | --- | --- |
| 95 and 169 minutes | 1 hour, 35 minutes | 2 hours, 49 minutes | 1 hour, 14 minutes |

I then ran the program in OnlineGDB and reported:

```text
Level 1: 1 hours and 35 minutes
Level 2: 2 hours and 49 minutes
Level 2 took longer by: 1 hours and 14 minutes
```

All three results agree with the predictions I recorded before running.
The difference is 74 minutes: one complete hour leaves 14 minutes.
### Restored values and final runs

I restored the assigned values to 78 and 144 minutes and ran the time
program again. I reported 1 hour and 18 minutes for Level 1, 2 hours and
24 minutes for Level 2, and an extra 1 hour and 6 minutes. I also reran
the diamond program. The saved final source uses 78 and 144.

As a supplementary check, Codex compiled and ran both saved sources locally
without compiler warnings. The diamond output matched the required seven
lines exactly, including spaces and newlines, and the time output matched
the assigned results above. These local checks were performed by Codex.

## Understanding the code

### Division and remainder

One hour is 60 minutes, so dividing by 60 converts minutes into hours.
The same idea applies to seconds because one minute is 60 seconds.
The remainder is what is left after division. For example, two hours fit
in 125 minutes because 60 plus 60 is 120. The remainder is 5 minutes.
AI clarified that the `int` operands in this program make division return
only the complete hours, and `%` returns the leftover minutes.

### Following the assigned values

`level1_minutes` starts with 78, giving 1 hour and 18 minutes.
`level2_minutes` starts with 144, giving 2 hours and 24 minutes.
The program subtracts the original minute totals. The corrected difference
is 66 minutes, which is stored in `extra_minutes` before being converted
to 1 hour and 6 minutes.

### Variables and the constant

Keeping values in variables makes the code more organized and easier to
check and change. Instead of writing 60 in every calculation, the program
defines it once as `MINUTES_PER_HOUR` and reuses it. If that value needed
to change, there would be one definition to update instead of many lines.
AI also explained that storing calculated answers separately lets each
answer be checked before the output statements display it.

## AI assistance

OpenAI Codex helped explain the assignment, draft the code, shorten variable
names at my request, and organize my answers into this README. My predictions
and personal runs are identified above. Codex also performed local compiler
syntax checks without warnings; those are supplementary agent checks.
See `AI_REFLECTION.md` for the tools used, a naming decision, a specific
personally tested result, and learning and practice goals.
