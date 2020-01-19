open Core
open Async

let command =
    Command.basic
        ~summary:"Simulate a sports league"
        (let open Command.Let_syntax in
            let%map_open filename = Command.Param.anon ("filename" %: string)
            in
            fun () ->
                let d_contents = Reader.file_contents filename in

                let () = print_endline "start" in

                Deferred.upon d_contents print_endline
        )

let () =
    Command.run command;

    never_returns (Scheduler.go ())
