# TDD sandbox

A minimal sandbox for exercising TDD.  


## TDD state machine problem.

Perform test driven development to create a class for each state, and bring them together into an integration test that runs them in the `StateMachineRunner` from the `state_machine` library.

Individual states will consume a single token from an input stream on each iteration and will: 

1. Transition to another state
2. Self transition
3. Not transition.

|      |   a  |   b  |   c  |
|------|------|------|------|
|**S1**|**S2**|      |**S3**|
|**S2**|**S2**|**S1**|**S3**|
|**S3**|**S1**|**S1**|      |

## Notes

* The code in this exercise as well as the library it incorporates build with CMake.
* You should be able to configure the cmake project out of the box.
* The repository includes a few tests with examples to illustrate linking gtest as well as the state machine library.
* Additional tests are also visible from the incorporated library.
* Parts of the problem are not well defined, you should figure them out.

## Supported tools

### vscode

A list of recommended extensions is supplied in the `extensions.json` in the `.vscode/` folder. 

### Known working configurations

As of time of authoring, tested and working with: 

|Platform|CMake|Compiler|
|-|-|-|
Windows 10| 3.18.6|MSVC 14.29.30133|
Ubuntu 20.04 | 3.16.3 | gcc 9.4.0|

## Working the problem

* Fork this repository on Github
* Perform the TDD activity outlined above as you understand it.
* Commit frequently **and** push your progress to github. 
* A review of your final solution and your github commits will be used in evaluation.
