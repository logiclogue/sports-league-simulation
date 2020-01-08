open Core

let () =
    let json_string = Node.Fs.readFileSync "./package.json" `ascii in

    let json_opt = Js.Json.parseExn json_string
        |> Js.Json.decodeObject
        |> OptionHelpers.bind (fun dict -> Js.Dict.get dict "name")
        |> OptionHelpers.bind Js.Json.decodeString in

    match json_opt with
    | Some name -> Js.log name
    | None      -> Js.log "Failed to parse"
