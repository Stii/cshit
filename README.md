cshit
=====

Some basic C programs which I do to learn C

You probably don't want to use this as it is newbie code for now, but comments would be appreciated.

## What is in it?
### ts2d
A command that convert a timestamp to a human readable date string and the other way round.

Needs lots of massaging still. No real checks are done, which must still happen.

To use it, on a *nix filesystem:
`$ cd ts2d && make dt`

### isleap
A command that calculates if a year was a leap year. The year must be between 0 9999.

To use it, on a *nix filesystem:
`$ cd isleap && make leap`

### Collatz Conjecture (Hailstone sequence)
A program that takes 2 integers as input and print these out together with the longest cycle of an int between the 2 params.

[https://github.com/Stii/cshit/tree/master/hailstone](Read the readme.)

To use it, on a *nix filesystem:
`$ cd hailstone && make hail`
