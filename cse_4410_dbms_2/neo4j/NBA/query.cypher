// Get all Nodes
MATCH (n)
RETURN count(n)

// Get label specific node
MATCH (team:TEAM)
RETURN team

MATCH (player:PLAYER)
RETURN player

MATCH (coach: COACH)
RETURN coach

// Get specific property of a node
MATCH (player:PLAYER)
RETURN player.number AS number, player.name AS name, player.age AS age, player.height AS height, player.weight AS weight

// Filter within a label
MATCH (lebron:PLAYER)
WHERE lebron.name = 'LeBron James'
RETURN lebron

// This can be achieved using a key-value pair
MATCH (lebron:PLAYER { name: 'LeBron James', number: 6 })
RETURN lebron

// Negative filter
MATCH (player:PLAYER)
WHERE player.name <> 'LeBron James'
RETURN player

// Filter with multiple conditions
MATCH (player:PLAYER)
WHERE player.age > 30 AND player.height > 2
RETURN player

// Filter with multiple conditions
MATCH (player:PLAYER)
WHERE player.age > 30 OR player.height > 2
RETURN player

// Multiple negative
MATCH (player:PLAYER)
WHERE NOT player.age < 30 AND player.height < 2
RETURN player

// Filter by BMI
MATCH (player:PLAYER)
WHERE (player.weight / (player.height * player.height)) < 23
RETURN player

// Order by
MATCH (player:PLAYER)
RETURN player.name AS Name, player.age AS Age
 ORDER BY player.age DESC

// Limit
MATCH (player:PLAYER)
RETURN player.name AS Name, player.age AS Age
 ORDER BY player.age DESC
LIMIT 10

// Skip
MATCH (player:PLAYER)
RETURN player.name AS Name, player.age AS Age
 ORDER BY player.age DESC
SKIP 5
LIMIT 5

// Multiple labels
MATCH (player:PLAYER), (team:TEAM)
RETURN player, team

// Multiple labels with filter
MATCH (player:PLAYER), (team:TEAM)
WHERE player.age > 30 AND player.height > 2 AND player.weight > 100 AND player.number = 6
RETURN player, team

// Querying relationships

// Get all relationships
MATCH ()-[r]->()
RETURN r

// Get all relationships with type
MATCH ()-[r:PLAYS_FOR]->()
RETURN r

// Get players who play for a team
MATCH (player:PLAYER) -[:PLAYS_FOR]-> (team:TEAM { name: 'LA Lakers' })
RETURN player AS Player, team AS Team

// Filter by relationship properties
MATCH (player:PLAYER) -[contract:PLAYS_FOR]-> (team:TEAM)
WHERE contract.salary > 40000000
RETURN player AS Player, contract.salary AS Salary, team.name AS Team

MATCH (player:PLAYER { name: 'LeBron James', number: 6 }) -[r:TEAMMATES]-> (teammate:PLAYER)
RETURN player.name AS Player, teammate.name AS Teammate

// Nested relationships
MATCH (player:PLAYER { name: 'LeBron James', number: 6 }) -[r:TEAMMATES]-> (teammate:PLAYER) -[r2:PLAYS_FOR]-> (team:TEAM)
RETURN player.name AS Player, teammate.name AS Teammate, team.name AS Team

MATCH (player:PLAYER { number: 6 }) -[r:TEAMMATES]-> (teammate:PLAYER) -[r2:PLAYS_FOR]-> (team:TEAM)
WHERE r2.salary > 40000000
RETURN player.name AS Player, teammate.name AS Teammate, team.name AS Team, r2.salary AS TeammateSalary

MATCH (player:PLAYER { name: 'LeBron James', number: 6 }) -[r:TEAMMATES]-> (teammate:PLAYER)
MATCH (teammate) -[r2:PLAYS_FOR]-> (team:TEAM)
WHERE r2.salary > 30000000
RETURN player.name AS Player, teammate.name AS Teammate, team.name AS Team, r2.salary AS TeammateSalary

// Aggregation
MATCH (player:PLAYER) -[games: PLAYED_AGAINST]-> (opponent:TEAM)
RETURN player.name AS Player, opponent.name AS Opponent, count(games) AS GamesPlayed

MATCH (player:PLAYER) -[games: PLAYED_AGAINST]-> (opponent:TEAM)
RETURN player.name AS Player, opponent.name AS Opponent, sum(games.points) AS PointsScored

MATCH (player:PLAYER) -[games: PLAYED_AGAINST]-> (opponent:TEAM)
RETURN player.name AS Player, opponent.name AS Opponent, avg(games.points) AS PointsScored ORDER BY PointsScored DESC
