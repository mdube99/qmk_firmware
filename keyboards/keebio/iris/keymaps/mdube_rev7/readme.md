How to actually use:

Compile & flash:

```
qmk compile -kb keebio/iris/rev3 -km mdube99

qmk flash -kb keebio/iris/rev3 -km mdube99
```

Where:
- keebio/iris/rev3 is the *relative* path for your keyboard/revision
- mdube99 is the keyboard layout. Can be found under 'keebio/iris/keymaps' in this case.

#### Setting up QMK config

```
qmk config default.keymap=mdube99

qmk config default.keyboard=keebio/iris/rev3
```
