open Framework;
open TennisKata.Game;

describe("Given PlayerOne then PlayerTwo is different", ({test}) => {
  test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo)
  })
});

describe("Given deuce when PlayerOne wins then score is correct", ({test}) => {
  test("Given deuce when PlayerOne wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerOne), Advantage(PlayerOne))
  });
});

describe("Given deuce when PlayerTwo wins then score is correct", ({test}) => {
  test("Given deuce when PlayerTwo wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerTwo), Advantage(PlayerTwo))
  });
});



describe("Given advantage when advantaged player wins then score is correct", ({test}) => {
  test("Given advantage when advantaged player wins then score is correct",({expect}) => {
      let advantagedPlayer = PlayerOne;
      let winner = advantagedPlayer;
      expect.equal(scoreWhenAdvantage(advantagedPlayer, winner),Game(advantagedPlayer),);
    });
});

describe("Given advantage when the other player wins then score is Deuce", ({test}) => {
  test("Given advantage when the other player wins then score is Deuce",({expect}) => {
      let advantagedPlayer = PlayerOne;
      let winner = other(advantagedPlayer);
      expect.equal(scoreWhenAdvantage(advantagedPlayer, winner),Deuce,);
    });
});

describe("Given player: 40 when wins then score is Game for this player", ({test}) => {
  test("Given player: 40 when wins then score is Game for this player",({expect}) => {
    let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
    expect.equal(scoreWhenForty(fortyThirty, fortyThirty.player),Game(fortyThirty.player),);
  });
});

describe("Given player: 40 | other : 30 when other wins then score is Deuce", ({test}) => {
  test("Given player: 40 | other : 30 when other wins then score is Deuce",({expect}) => {
     let fortyThirty = {player: PlayerOne, otherPlayerPoint: Thirty};
     expect.equal(scoreWhenForty(fortyThirty, other(fortyThirty.player)),Deuce,);
   });
});


describe("Given player: 40 | other : 0 when other wins then score is fortyFifteen", ({test}) => {
  test("Given player: 40 | other : 0 when other wins then score is fortyFifteen",({expect}) => {
      let fortyLove = {player: PlayerOne, otherPlayerPoint: Love};
      let fortyFifteen = {player: PlayerOne, otherPlayerPoint: Fifteen};
      expect.equal(scoreWhenForty(fortyLove, other(fortyLove.player)),Forty(fortyFifteen),);
    });
});

describe("Given player: 15 | other : 15 when player wins then score is 30/15", ({test}) => {
  test("Given player: 15 | other : 15 when player wins then score is 30/15",({expect}) => {
    let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    expect.equal(
      scoreWhenPoints(fifteenFifteen, PlayerOne),
      Points(thirtyFifteen)
    );
  });
});

describe("Given player: 0 | other : 15 when other wins then score is 0/30", ({test}) => {
  test("Given player: 0 | other : 15 when other wins then score is 0/30",({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
    let loveThirty = {playerOne: Love, playerTwo: Thirty};
    expect.equal(
      scoreWhenPoints(loveFifteen, other(PlayerOne)),
      Points(loveThirty)
    );
  });
});


describe("Given player: 30 | other : 15 when player wins then score is 40/15", ({test}) => {
  test("Given player: 30 | other : 15 when player wins then score is 40/15",({expect}) => {
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    expect.equal(
      scoreWhenPoints(thirtyFifteen, PlayerOne),
      Forty({ player:PlayerOne, otherPlayerPoint:Fifteen })
    );
  });
});



// Tests for function "string_of_player"
describe("Test function string_of_player Player 1", ({test}) => {
  test("Print Player 1",
    ({expect}) => {
      expect.equal(
        string_of_player(PlayerOne),
        "Player 1"
      );
  });
});
describe("Test function string_of_player Player 2", ({test}) => {
  test("Print Player 2",
    ({expect}) => {
      expect.equal(
        string_of_player(PlayerTwo),
        "Player 2"
      );
  });
});
// Tests for function "string_of_point"
describe("Test for function string_of_point", ({test}) => {
  test("Print Love Point",
    ({expect}) => {
      expect.equal(
        string_of_point(Love),
        "0"
      );
   });
});
describe("Test for function string_of_point", ({test}) => {
  test("Print Fifteen score",
    ({expect}) => {
      expect.equal(
        string_of_point(Fifteen),
        "15"
      );
  });
});
describe("Test for function string_of_point", ({test}) => {
  test("Print Thirty score",
    ({expect}) => {
      expect.equal(
        string_of_point(Thirty),
        "30"
      );
  });
});
describe("Test for function string_of_point", ({test}) => {
  test("Print Forty score",
    ({expect}) => {
      expect.equal(
        string_of_point(Forty),
        "40"
      );
  });
});
//Tests for function "string_of_score"
describe("Test for function string_of_score", ({test}) => {
  test("Score Fifteen/Thirty",
    ({expect}) => {
      let fifteenThirty = {playerOne : Fifteen, playerTwo : Thirty};
      expect.equal(
        string_of_score(Points(fifteenThirty)),
        "15/30"
      );
  });
});
describe("Test for function string_of_score", ({test}) => {
  test("Score Love/Fifteen",
    ({expect}) => {
      let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
      expect.equal(
        string_of_score(Points(loveFifteen)),
        "0/15"
      );
  });
});
describe("Test for function string_of_score", ({test}) => {
  test("Score Deuce",
    ({expect}) => {
      expect.equal(
        string_of_score(Deuce),
        "40/40 : Deuce"
      );
  });
});
describe("Test for function string_of_score", ({test}) => {
  test("Advantage for Player 1",
    ({expect}) => {
      expect.equal(
        string_of_score(Advantage(PlayerOne)),
        "Advantage for Player 1"
      );
  });
});
describe("Test for function string_of_score", ({test}) => {
  test("Advantage for Player 2",
    ({expect}) => {
      expect.equal(
        string_of_score(Advantage(PlayerTwo)),
        "Advantage for Player 2"
      );
  });
});
describe("Test for function string_of_score", ({test}) => {
  test("The winner is Player 1",
    ({expect}) => {
      expect.equal(
        string_of_score(Game(PlayerOne)),
        "Winner is Player 1"
      );
  });
});
describe("Test for function string_of_score", ({test}) => {
  test("The winner is Player 2",
    ({expect}) => {
      expect.equal(
        string_of_score(Game(PlayerTwo)),
        "Winner is Player 2"
      );
  });
});
describe("Test for function string_of_score 40/0", ({test}) => {
  test("Score 40/0",
    ({expect}) => {
      let forty = {player: PlayerOne, otherPlayerPoint: Love};
      expect.equal(
        string_of_score(Forty(forty)),
        "Player 1 : 40/0 : Player 2"
      );
  });
});
describe("Test for function string_of_score 15/40", ({test}) => {
  test(
    "Score 15/40",
    ({expect}) => {
      let forty = {player: PlayerTwo, otherPlayerPoint: Fifteen};
      expect.equal(
        string_of_score(Forty(forty)),
        "Player 1 : 15/40 : Player 2"
      );
  });
});