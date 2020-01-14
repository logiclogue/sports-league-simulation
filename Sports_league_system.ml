open Core

let command =
    Command.basic
        ~summary:"Simulate a sports league"
        (let open Command.Let_syntax in
            let%map_open filename = Command.Param.anon ("filename" %: string)
            in
            fun () ->
                print_endline filename
        )

let () = Command.run command
