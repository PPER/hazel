# Hazel

Hazel is a live functional programming environment rooted in the principles 
of type theory. You can find the relevant papers and more motivation at 
[the Hazel website](http://hazel.org/).

## Building Hazel
You can build Hazel using the following instructions.

### Prerequisites

Hazel is implemented in Coq and Reason/OCaml, and is compiled to Javascript for the web browser via the `js_of_ocaml` compiler. An easy way to install both OCaml and the necessary libraries is to install [opam](https://opam.ocaml.org/). After having installed `opam` using the instructions on their website, follow these steps:

  - Make sure opam is updated:
  
  ```sh
    > opam update
  ```

  - You need a version 4.04.2+ of the OCaml compiler. First check the current version used by `opam`:

    ```sh
    > opam switch
    --     -- 3.11.2  Official 3.11.2 release
    --     -- 3.12.1  Official 3.12.1 release
    --     -- 4.00.0  Official 4.00.0 release
    --     -- 4.00.1  Official 4.00.1 release
    --     -- 4.01.0  Official 4.01.0 release
    --     -- 4.02.0  Official 4.02.0 release
    --     -- 4.02.1  Official 4.02.1 release
    --     -- 4.02.2  Official 4.02.2 release
    --     -- 4.02.3  Official 4.02.3 release
    --     -- 4.03.0  Official 4.03.0 release
		--     -- 4.04.0  Official 4.04.0 release
    --     -- 4.04.1  Official 4.04.1 release
    --     -- 4.04.2  Official 4.04.2 release
    --     -- 4.06.0  Official 4.06.0 release
    --     -- 4.06.1  Official 4.06.1 release
    system  C system  System compiler (4.02.1)
    ```

    The `C` marks the current compiler. Here version 4.02.1 is installed. We can see that a more recent version is available (4.06.1). So we will install it as follows:

    ```sh
    > opam switch 4.04.2
    > eval `opam config env`
    ```

    This won't remove the system compiler as `opam` will install the files in your `.opam` directory.

  - We also need Coq:

    ```sh
    > opam install coq
    ```

  - Finally, we can now install the necessary OCaml dependencies:

    ```sh
    > opam install reason reason-parser js_of_ocaml tyxml deriving ppx_deriving reactiveData js_of_ocaml-tyxml camomile menhir oUnit
    ```
    
### Compilation

We can now build the application.

```sh
> cd src
> make
```

From a fresh checkout, `make` does three things:

1. Extracts the semantics from the Coq file, `Semantics.v`.
2. Compiles the `Hazel.re` file to OCaml bytecode, `Hazel.byte`, with the `rebuild` command.
3. Compiles `Hazel.byte` to `www/hazel.js`, with the `js_of_ocaml` compiler.

### Debugging
You can use `make debug` instead of `make`. This differs only in that we pass the --debuginfo flag to `js_of_ocaml`, which causes the insertion of comments mapping locations in the generated JS to locations in the source files. This is useful for debugging purposes, but causes a substantial increase in compilation time and file size, so it is disabled by default.

### Results
You can now open src/www/hazel.html in a browser to see Hazel in action.

