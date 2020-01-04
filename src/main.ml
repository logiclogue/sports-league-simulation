let () =
    let json_string = Node.Fs.readFileSync "./package.json" `ascii in

    let json = Js.Json.parseExn json_string in

    Js.log (Js.Json.stringify json)
