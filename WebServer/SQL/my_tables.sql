
CREATE TABLE IF NOT EXISTS user (
    uid int primary key auto_increment,
    usr varchar(20) unique not null ,
    pwd varchar(20) unique not null ,
    email varchar(20) unique not null
);

CREATE TABLE IF NOT EXISTS song_message (
    song_id int primary key auto_increment,
    song_name varchar(20) not null ,
    singer varchar(20) not null ,
    duration int not null ,
    url varchar(30) unique not null ,
    UNIQUE (singer, song_name)
);

CREATE TABLE IF NOT EXISTS song_list (
    uid int references text.user(uid),
    song_id int references  song_message(song_id)
);

DROP PROCEDURE IF EXISTS reg_user;
DROP PROCEDURE IF EXISTS add_song_id_to_song_list;
DROP PROCEDURE IF EXISTS remove_song_id_from_song_list;

DELIMITER \\
CREATE PROCEDURE reg_user(
	in usr_ varchar(20),
	in email_ varchar(20),
	in pwd_ varchar(20),
    out result int)
BEGIN
	INSERT INTO user(usr, pwd, email)
	VALUE(usr_, pwd_, email_);
END \\
DELIMITER ;


DELIMITER \\
CREATE PROCEDURE add_song_id_to_song_list(
    in id_ int,
    in singer_ varchar(20),
    in song_name_ varchar(20))
BEGIN
	INSERT INTO song_list(id, song_id) 
	VALUES(
		SELECT id_, song_message.song_id
		FROM song_message 
		WHERE singer = singer_ and song_name = song_name_
	);
END \\
DELIMITER ;


DELIMITER \\
CREATE PROCEDURE remove_song_id_from_song_list(
    in id_ int,
    in singer_ varchar(20),
    in song_name_ varchar(20))
BEGIN
	DELETE FROM song_list
	WHERE uid = id_
	AND song_list.song_id IN
	(
		SELECT song_message.song_id
		FROM song_message 
		WHERE singer = singer_ AND song_name = song_name_
	);
END \\
DELIMITER ;


DELIMITER \\
CREATE PROCEDURE check_song_exist(
    in id_ int,
    in singer_ varchar(20),
    in song_name_ varchar(20),
	out res int)
BEGIN
	SELECT COUNT(1)
	FROM song_list
	WHERE song_list.uid = id_
	AND song_list.song_id IN (
		SELECT song_message.song_id
		FROM song_message
		WHERE song_message.singer = singer_
		and song_message.song_name = song_name_
	);
END \\
DELIMITER ;

CREATE INDEX index_user
ON user (usr ASC);

CREATE INDEX 