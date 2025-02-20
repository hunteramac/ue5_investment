A prototype project following what I've learned in previous ones. The intent is to build and apply a toolset to effectively create gameplay expeirences with NPC social interaction.

Has important dependency of https://github.com/MothCocoon/FlowGraph

Currently, there's some flow nodes setup in a style similar to how The Witcher 3 REDKIT has internal scenes defined. They take in data tables which represent Screenplay. It's all text based right now.

Not in this repo, I've got a hacked together tool which takes an Obsidian Vault where the writer defines the screen play, and converts to the csv data table format these UE5's flow nodes use. 
-> A temporary soloution until I can get a proper editor experience setup which sits on top of underlying data tables and gives writer a proper editing expeirence seamlessly in conjunction with the graphical editor.
