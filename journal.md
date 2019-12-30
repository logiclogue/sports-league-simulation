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
