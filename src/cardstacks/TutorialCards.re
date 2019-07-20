module Vdom = Virtual_dom.Vdom;
module Attr = Vdom.Attr;

let deserialize = s => UHExp.block_of_sexp(Sexplib.Sexp.of_string(s));

let div = Vdom.Node.div;
let span = Vdom.Node.span;
let txt = Vdom.Node.text;
let p = Vdom.Node.p;
let ptxt = s => p([], [txt(s)]);

let code = s => span([Vdom.Attr.classes(["code"])], [txt(s)]);
let keyblock = s => span([Vdom.Attr.classes(["keyblock"])], [txt(s)]);

let intro_caption =
  div(
    [],
    [
      txt(
        "Welcome to Hazel, a live functional programming environment organized around typed holes.",
      ),
      ptxt("Below is our very first hole, numbered automatically as shown."),
      p(
        [],
        [
          txt(
            "Fill hole 1 with a number literal by placing the caret before or after the hole and typing in ",
          ),
          code("12345"),
          txt("."),
        ],
      ),
      ptxt("Click Next to go to the next card once you are finished."),
    ],
  );
let intro_init_block = deserialize("(Block()(EmptyHole 0))");
let intro_card: Card.t = {
  caption: intro_caption,
  init_block: intro_init_block,
};

let backspace_caption =
  div(
    [],
    [
      txt("You can use "),
      keyblock("Backspace"),
      txt(" and "),
      keyblock("Delete"),
      txt(
        " to delete digits. Once you've deleted all of the digits, a hole again appears!",
      ),
      ptxt("Go ahead and delete all of the digits below to try it out."),
    ],
  );
let backspace_init_block = deserialize("(Block()(NumLit NotInHole 12345))");
let backspace_card: Card.t = {
  caption: backspace_caption,
  init_block: backspace_init_block,
};

let cardstack: CardStack.t = [intro_card, backspace_card];
