Rust:
    word_counter.rs
        -- A file that takes in a text file and counts the words within it before printing out the top 20. 
        -- Compile with:
            Compiled with rustc word_counter.rs
            Run with ./word_counter <text file> ex. test.txt
        -- Outputs:
            In file test.txt
            Sorted list in descending order:

            the     17
            of      7
            and     6
            was     5
            with    4
            in      4
            a       3
            windows 3
            central 2
            portion 2
            wings   2
            were    2
            broken  2
            but     2
            up      2
            had     2
            been    2
            building        1
            grey    1
            lichen-blotched 1
    error_handling.rs
        -- A test file to examine the way rust can handle errors.  
        -- Compile with:
            Compiled with rustc error_handling.rs
            Run with ./error_handling
        -- Outputs:
            3000
            thread 'main' panicked at 'called `Result::unwrap()` on an `Err` value: Os { code: 2, kind: NotFound, message: "The system cannot find the file specified." }', .\error_handling.rs:28:54
            note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
    fileio.rs
        -- A test file to examine input and output of both command line and files 
        -- Compile with:
            Compiled with rustc fileio.rs
            Run with ./fileio <text file> ex test.txt
        -- Outputs:
            The building was of grey, lichen-blotched stone, with a high central portion 
            and two curving wings, like the claws of a crab, thrown out on each side. In one 
            of these wings the windows were broken and blocked with wooden boards, while the 
            roof was partly caved in, a picture of ruin. The central portion was in little better 
            repair, but the right-hand block was comparatively modern, and the blinds in the windows, 
            with the blue smoke curling up from the chimneys, showed that this was where the family 
            resided. Some scaffolding had been erected against the end wall, and the stone-work had 
            been broken into, but there were no signs of any workmen at the moment of our visit. 
            Holmes walked slowly up and down the ill-trimmed lawn and examined with deep attention 
            the outsides of the windows.

            What is your name :
            Sawyer
            Hey, Sawyer