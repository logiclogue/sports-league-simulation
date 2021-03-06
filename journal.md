# 26 December 2019

Using the requirements, the basic domain must be sketched out.

# 27 December 2019

Sketching out the domain in `Domain.ml`.

# 28 December 2019

Continuing to sketch out the domain.

Completed sketching out the domain. The next step is to start implementing
certain parts of the domain in different files. Make sure to unit test them.

# 29 December 2019

Before implementing the domain, I'm going to sketch out some of the
requirements.

## Requirements

I want it to be a command line system similar to ledger which reads from a human
readable text file.

The results will be saved in a human readable text file. The application will
read from the text file. The text file will contain a seed, a list of
teams/players and their properties (such as ratings), and most importantly a
list of the user's results.

The application itself will read in the text file. From that, it will generate a
fixture list. It will generate a league table. It will simulate the other
matches that the user isn't in charge of.

## Analysis of requirements

In order to make this work, there will have to be a Domain Specific Language
(DSL) which represents the text file. At first it may be sensible to represent
this in JSON form, just to get the application off the ground.

## JSON text file format

```
{
    "seed": string,
    "fixed_ratings": bool (default false),
    "rating_k_factor": int (default 32),
    "teams": [{
        team_name: string,
        rating: int,
        user_controlled: bool (default false)
    }],
    "results": [{
        home_team: string,
        home_result: int,
        away_result: int,
        away_team: string
    }]
}
```

This JSON parser also needs to be implemented. It needs to be implemented both
as a domain model and as the actual code which transforms:

```
val parse : jsonDocument -> (state * parseErrorCode) either
```

This should be thought of until the end, along with command line arguments. The
main goal is to get a bare-bones system working and then flesh out the rest.

## Updating the domain

Now it's time to further update the domain from what has just been specified.
The new domain will take into account the `seed` and state.

Generating fixture lists needs to be part of the domain.

# 3 January 2020

It's time to start implementing the domain.

I think there should be a main state, which will be quite closely mapped to the
JSON definition.

## JSON text file format

```
{
    "seed": string,
    "fixed_ratings": bool (default false),
    "rating_k_factor": int (default 32),
    "teams": [{
        team_name: string,
        rating: int,
        user_controlled: bool (default false)
    }],
    "results": [{
        home_team: string,
        home_result: int,
        away_result: int,
        away_team: string
    }]
}
```

## State

```
{
    seed: string
    fixed_ratings: bool
    rating_k_factor: int
    teams: [{
        team_name: string
        rating: int
        user_controlled: bool
    }]
    results: [{
        home_team: string
        home_result: int
        away_result: int
        away_team: string
    }]
}
```

This will also require the team and result entities.

Added the `State.ml` file.

Need to install bsb now.

That is installed, the next step it to start thinking about how the state will
be updated.

# 4 January 2020

I think, instead of going to write the core part of the code. The best idea
would be to get something which reads in a text file first before trying to do
any of the logic. This way I have a basic application.

The first step is having `mail.ml` and having it compile and run hello world.

Issue with the domain while compiling.

The works by typing `node src/mail.bs.js`.

# 5 January 2020

Successfully parses `name` field in `package.json`. Update this so that it
parses my own json file.

# 8 January 2020

Switch to using standard OCaml with the Jane Street Core library. Reason for
this is poor standard library in Bucklescript and application is command line
anyway.

# 9 January 2020

# 10 January 2020

Convert it to an OCaml project.

# 14 January 2020

So I'm trying to use the `Core` library to make a command line application. It's
failing because for some reason I can't use `[%map_open ]` due to `Let_syntax`
missing.

Now that I've setup the command line, I need to read in a file and parse it as
JSON.

# 19 January 2020

Open a file. `open_in`. To get an `in_channel`.

Playing around with the `Async` library. Program not terminating after reading
in the file.

# 6 February 2020

Build issues with `ppx_jane` not being found.
